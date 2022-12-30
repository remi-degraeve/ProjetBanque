#pragma once

#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <fstream>

#ifdef _WIN32
#include <SDKDDKVer.h>
#endif

#include "Class_Banque.h"

using boost::property_tree::ptree;
using boost::property_tree::read_json;
using boost::property_tree::write_json;


ptree get_a_ptree_from_a_banque_dec(class_Banque_Dec& Banque_dec);

class_Banque_Dec get_a_banque_dec_from_a_ptre(ptree& pt);