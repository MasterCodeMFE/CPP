#include "Data.hpp"
#include "Serialize.hpp"

int main()
{
    Data data;
    data.value = -33;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Raw: " << raw << std::endl;

    Data* ptr2 = Serializer::deserialize(raw);
    std::cout << "ptr2: " << ptr2->value << std::endl;
    delete ptr2;
    return 0;
}