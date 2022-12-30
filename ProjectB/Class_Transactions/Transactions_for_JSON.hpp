#pragma once

#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <fstream>

#ifdef _WIN32
#include <SDKDDKVer.h>
#endif

#include "Class_Transactions.h"

using boost::property_tree::ptree;
using boost::property_tree::read_json;
using boost::property_tree::write_json;


ptree get_a_ptree_from_a_transaction(Transactions& transaction);

Transactions get_a_transaction_from_a_ptree(ptree& pt);