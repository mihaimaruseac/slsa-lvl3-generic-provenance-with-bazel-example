cc_binary(
  name = "fib2",
  srcs = ["fib.cc"],
)

cc_library(
  name = "lib",
  srcs = ["lib.cc"],
  hdrs = ["lib.h"],
)

cc_binary(
  name = "test",
  srcs = ["test.cc"],
  deps = [":lib"],
)

cc_binary(
  name = "runfiles",
  srcs = ["runfiles.cc"],
  deps = ["@bazel_tools//tools/cpp/runfiles"],
  data = ["test.txt"],
)
