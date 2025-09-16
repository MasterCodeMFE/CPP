#include "BitcoinExchange.hpp"

bool isLeapYear(int year)
{
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

bool isValidDate(const std::string& date)
{
    if (date.length() != 10)
    {
        return false;
    }

    if (date[4] != '-' || date[7] != '-')
    {
        return false;
    }

    for (int i = 0; i < 10; ++i)
    {
        if ((i < 4 || (i > 4 && i < 7) || i > 7) && !isdigit(date[i]))
        {
            return false;
        }
        if ((i == 4 || i == 7) && date[i] != '-')
        {
            return false;
        }
    }

    int year, month, day;
    std::istringstream yearStream(date.substr(0, 4));
    yearStream >> year;

    std::istringstream monthStream(date.substr(5, 2));
    monthStream >> month;

    std::istringstream dayStream(date.substr(8, 2));
    dayStream >> day;

    if (month < 1 || month > 12)
    {
        return false;
    }

    if (day < 1)
    {
        return false;
    }
    
    const int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    
    if (month == 2 && isLeapYear(year))
    {
        if (day > 29)
        {
            return false;
        }
    }
    else if (day > daysInMonth[month])
    {
        return false;
    }

    return true;
}

bool isValidValue(float value)
{
	if(value >= 0 && value <= 1000)
		return true;
	else
		return false;
}

void findClosestDate(const std::map<std::string, float>& bitcoinData, const std::string& userDate, float userBtc)
{
    // Si no se encuentra la fecha, buscar la más cercana hacia abajo
    std::map<std::string, float>::const_iterator closestIt = bitcoinData.lower_bound(userDate);
    
    if (closestIt == bitcoinData.begin())
    {
        // No hay ninguna fecha anterior
        std::cerr << "Error: No earlier dates found in Bitcoin data." << std::endl;
    }
    else
    {
        // Retroceder un iterador para obtener la fecha más cercana hacia abajo
        --closestIt;
        float btcValue = closestIt->second; // Precio del BTC en la fecha más cercana
        float totalMoney = userBtc * btcValue; // Dinero total del usuario

        std::cout << "Closest date: " << closestIt->first 
                    << ", User BTC: " << userBtc 
                    << ", BTC price on that date: " << btcValue 
                    << ", Total money: " << totalMoney << std::endl;
    }
}

// Usamos std::map<std::string, float> para:
// - Ordenar automáticamente las fechas (formato YYYY-MM-DD)
// - Garantizar claves únicas (sin fechas duplicadas)
// - Acceder a tasas de cambio en O(log n)
// - Iterar fácilmente en orden cronológico
// Ideal para almacenar y consultar tasas de cambio de Bitcoin por fecha.
void bitcoinExchange(char **argv)
{
    std::map<std::string, float> bitcoinData; // Usar std::map en lugar de std::unordered_map
    std::map<std::string, float> userData;    // Usar std::map en lugar de std::unordered_map

    // Abrir archivo de datos de Bitcoin
    std::ifstream file("data.csv");
    if (!file)
    {
        std::cerr << "Error: Could not open file data.csv" << std::endl;
        return;
    }

    std::string line; // Para almacenar cada línea del archivo
    // Leer el archivo línea por línea
	std::getline(file, line);
    while (std::getline(file, line))
    {
        std::string date;
        float value;

        // Usar stringstream para dividir la línea
        std::stringstream ss(line);
        std::getline(ss, date, ','); // Leer la fecha
        ss >> value; // Leer el valor (exchange rate)

        // Asegurarse de que se leyeron correctamente
        if (ss.fail())
        {
            std::cerr << "Warning: Failed to read line in data.csv => " << line << std::endl;
            continue; // Si hay un error de conversión, continuar con la siguiente línea
        }

        // Almacenar los datos en el mapa
        bitcoinData[date] = value; // Guardamos la fecha y el valor
    }
    file.close();

    // Abrir archivo del usuario
    std::ifstream fileUser(argv[1]);
    if (!fileUser)
    {
        std::cerr << "Error: Could not open file " << argv[1] << std::endl;
        return;
    }

    // Saltar la cabecera
    std::getline(fileUser, line);

    // Leer los datos del archivo línea por línea
    while (std::getline(fileUser, line))
	{
		std::stringstream ss(line); // Usar un stringstream para dividir la línea
		std::string dateUser;
		std::string valueUserStr;

		// Leer la fecha y el valor separados por '|'
		if (std::getline(ss, dateUser, '|') && std::getline(ss, valueUserStr))
		{
			// Trim whitespace from dateUser and valueUserStr
			dateUser.erase(dateUser.find_last_not_of(" \n\r\t") + 1); // Trim right
			valueUserStr.erase(0, valueUserStr.find_first_not_of(" \n\r\t")); // Trim left

			// Convertir valueUserStr a float
			float valueUser;
			std::istringstream valueStream(valueUserStr);
			valueStream >> valueUser; // Intentar convertir a float

			// Verificar si la conversión fue exitosa
			if (valueStream.fail() || !valueStream.eof())
			{
				continue; // Si hay un error de conversión, continuar con la siguiente línea
			}

			// Almacenar en userData solo si la conversión fue exitosa
			userData[dateUser] = valueUser; // Almacenar en userData
		}
		else 
		{
			std::cerr << "Warning: Failed to parse line in user file => " << line << std::endl; // Debug output
		}
	}
    fileUser.close();

    // Procesar los datos del usuario
    for (std::map<std::string, float>::const_iterator it = userData.begin(); it != userData.end(); ++it)
    {
        const std::string& userDate = it->first;
        float userBtc = it->second; // Cantidad de BTC que tiene el usuario


        // Validar la fecha primero
        if (!isValidDate(userDate))
        {
            std::cerr << "Error: bad date => " << userDate << std::endl;
            continue;
        }

        // Validar el valor (cantidad de BTC)
        if (!isValidValue(userBtc))
        {
            if (userBtc < 0)
            {
                std::cerr << "Error: not a positive number." << std::endl;
            }
            else if (userBtc > 1000)
            {
                std::cerr << "Error: too large a number." << std::endl;
            }
            continue;
        }

        // Buscar la fecha en `bitcoinData`
        std::map<std::string, float>::iterator btcIt = bitcoinData.find(userDate);
        if (btcIt != bitcoinData.end()) // Si la fecha existe en bitcoinData
        {
            float btcValue = btcIt->second; // Precio del BTC en esa fecha
            float totalMoney = userBtc * btcValue; // Dinero total del usuario

            std::cout << "Date: " << userDate 
                      << ", User BTC: " << userBtc 
                      << ", BTC price on that date: " << btcValue 
                      << ", Total money: " << totalMoney << std::endl;
        }
        else
        {
            findClosestDate(bitcoinData, userDate, userBtc);
        }
    }
}
	