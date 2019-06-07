/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the LICENSE
 * file in the root directory of this source tree.
 */
#include "TestFunctions.h"

namespace facebook {
namespace hermes {
namespace synthtest {

const char *getPropertyNamesTrace() {
  return R"###(
{
  "version": 2,
  "globalObjID": 1,
  "env": {
    "mathRandomSeed": 0,
    "callsToDateNow": [],
    "callsToNewDate": [],
    "callsToDateAsFunction": []
  },
  "trace": [
    {
      "type": "CreateHostFunctionRecord",
      "time": 0,
      "objID": 10
    },
    {
      "type": "SetPropertyRecord",
      "time": 0,
      "objID": 1,
      "propName": "hostGetPropertyNamesOf",
      "value": "object:10"
    },
    {
      "type": "BeginExecJSRecord",
      "time": 0
    },
    {
      "type": "CallToNativeRecord",
      "time": 0,
      "functionID": 10,
      "thisArg": "undefined:",
      "args": ["object:11"]
    },
    {
      "type": "GetPropertyNamesRecord",
      "time": 0,
      "objID": 11,
      "propNamesID": 12
    },
    {
      "type": "ReturnFromNativeRecord",
      "time": 0,
      "retval": "object:12"
    },
    {
      "type": "EndExecJSRecord",
      "retval": "undefined:",
      "time": 0
    }
  ]
}
)###";
}

const char *getPropertyNamesSource() {
  return R"###(
'use strict';

(function(global) {
  var a = {x: 1, y: "hello", z: 4};
  var b = global.hostGetPropertyNamesOf(a);
  var expected = ["x", "y", "z"];
  if (b.length < expected.length) {
    throw new Error("b should contain all the property names of a");
  }
  for (var i = 0; i < b.length; i++) {
    if (b[i] != expected[i]) {
      throw new Error("No match: b[" + i + "] = " + b[i] + ", expected[" + i + "] = " + expected[i]);
    }
  }
})(this);
)###";
}

} // namespace synthtest
} // namespace hermes
} // namespace facebook
