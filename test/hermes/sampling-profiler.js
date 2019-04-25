// RUN: %hermes -O -Wno-direct-eval -sample-profiling %s
// RUN: %hermes -O -Wno-direct-eval -sample-profiling -emit-binary -out %t.hbc %s && %hermes %t.hbc

// NOTE: This test is here to check that the sampling profiler can play nicely
// with the multiple domains.
var global = this;
print(eval('global.x = function() {}'));
print(eval('global.x = function() {var y = 100}'));
print(eval('global.x = function() {var y = 3100}'));
