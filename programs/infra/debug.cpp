#define DEBUG
#ifdef DEBUG
cout << "Hello world";
#endif
#ifdef DEBUG
#define DEBUG_OUT(x) cout << x;
#else
#define DEBUG_OUT(x)
#endif
DEBUG_OUT("Hello world")
