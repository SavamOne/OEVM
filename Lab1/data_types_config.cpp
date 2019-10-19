#pragma once
#include "data_types_config.h"

data_types dtf[] = {
							data_types("int", processing_number<int, true>),
							data_types("short int", processing_number<short, true>),
							data_types("long int", processing_number<long, true>),
							data_types("long long int", processing_number<long long, true>),
							data_types("unsigned int", processing_number<unsigned int, false>),
							data_types("unsigned short int", processing_number<unsigned short, false>),
							data_types("unsigned long int", processing_number<unsigned long, false>),
							data_types("unsigned long long int", processing_number<unsigned long long , false>),
							data_types("float", processing_number<float, true>),
							data_types("double", processing_number<double, true>),
							data_types("long double", processing_number<long double, true>),
							data_types("char", processing_char)
};

short dtf_size = sizeof(dtf) / sizeof(data_types);