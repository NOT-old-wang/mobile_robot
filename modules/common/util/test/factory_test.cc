/*
Copyright 2019 undefined

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include <string>

#include "gtest/gtest.h"
#include "modules/common/util/factory.h"

class Base {
 public:
  virtual std::string Name() const { return "base"; }
};

class Derived : public Base {
 public:
  virtual std::string Name() const { return "derived"; }
};

TEST(FactoryTest, Register) {
  Factory<std::string, Base> factory;
  EXPECT_TRUE(factory.Register("derived_class",
                               []() -> Base* { return new Derived(); }));
  auto derived_ptr = factory.CreateObject("derived_class");
  EXPECT_NE(nullptr, derived_ptr);
  EXPECT_EQ("derived", derived_ptr->Name());
  auto non_exist_ptr = factory.CreateObject("non_exist_class");
  EXPECT_EQ(nullptr, non_exist_ptr);
}