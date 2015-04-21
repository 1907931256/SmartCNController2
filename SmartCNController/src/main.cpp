#include <qt/QtApp.h>

#include <cbang/ApplicationMain.h>
#include <cbang/js/Javascript.h>

// This causes Windows to not automatically create a console
#if defined(_WIN32) && !defined(DEBUG)
#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
#endif

using namespace std;


int main(int argc, char *argv[]) {
  // Look for v8 args after --
  bool foundV8Args = false;

  for (int i = 1; i < argc; i++)
    if (string("--") == argv[i]) {
      vector<char *> args;

      args.push_back(argv[0]);
      for (int j = i + 1; j < argc; j++) args.push_back(argv[j]);

      int v8Argc = argc - i + 1;
      cb::js::Javascript::init(&v8Argc, &args[0]);

      argc = i;
    }

  if (!foundV8Args) cb::js::Javascript::init(0, 0);

  return cb::doApplication<OpenSCAM::QtApp>(argc, argv);
}