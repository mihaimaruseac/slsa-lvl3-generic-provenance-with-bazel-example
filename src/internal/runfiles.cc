#include <fstream>
#include <iostream>
#include <string>
#include <memory>

#include "tools/cpp/runfiles/runfiles.h"

int main(int argc, char** argv) {
  // See https://github.com/bazelbuild/bazel/blob/master/tools/cpp/runfiles/runfiles_src.h
  std::string error;
  std::unique_ptr<bazel::tools::cpp::runfiles::Runfiles> runfiles(
      bazel::tools::cpp::runfiles::Runfiles::Create(argv[0], &error));

  if (!runfiles) {
    std::cerr << "Error creating runfiles: " << error << "\n";
    return 1;
  }

  // TODO: is this a bug? I wasn't expecting to have to type this much
  std::string path = runfiles->Rlocation("_main/src/internal/test.txt");
  if (path.empty()) {
    std::cerr << "Got empty path... :( \n";
    return 1;
  }

  std::cout << "Runfile path \"" << path << "\"\n";

  std::fstream file(path, std::ios::in);
  if (!file.is_open()) {
    std::cerr << "Failed to open file \n";
    return 1;
  }

  std::string line;
  int i = 0;
  while (std::getline(file, line)) {
    std::cout << i++ << ": " << line << "\n";
  }

  file.close();
  return 0;
}

