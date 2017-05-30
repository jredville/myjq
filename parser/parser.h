#pragma once

#include <string>
#include <unordered_map>

#include <boost/variant.hpp>

namespace parser {
  class Object;
  using Value = boost::variant<Object,std::string>;

  class Object {
    std::unordered_map<const std::string, Value> elements;
  };
}
