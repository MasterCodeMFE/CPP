#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <stdint.h> 
#include <string>
#include <iostream>
#include "Data.hpp"


class Serializer
{
    private:
        Serializer();
        ~Serializer();
        Serializer(const Serializer& other);
        Serializer& operator=(const Serializer& other);
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);

};

#endif