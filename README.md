# ns_hash
[![Build Status][WorkflowBadge]][WorkflowUrl]

Hash experiments, using [vade](https://github.com/nsauzede/vade) and [licensed under GPL-3.0 license](LICENSE)
- [x] MD5
- [ ] SHA1
- [ ] MD5 collisions ?
- [ ] ??

# How to test

## Prerequisite
[vade](https://github.com/nsauzede/vade) is required to build/test, etc..
```
$ git clone https://github.com/nsauzede/vade
```

## Run build/test
```
$ ./vade/vade clean test
    RM  pkg
    RM  bin
    CC  md5.o
    AR  md5.a
    AR  libmd5.a
    CC  md5_test.o
    CC  test.o
    AR  md5_test.a
    AR  libmd5_test.a
    CXX md5_test.exe
    RUN ./bin/md5_test.exe
[==========] Running tests from test suite.
[----------] Global test environment set-up.
[ RUN      ] md5_TestMd5_
[       OK ] md5_TestMd5_ (0 ms)
[----------] Global test environment tear-down
[==========] 1 tests from test suite ran. (0 ms total)
[  PASSED  ] 1 tests.
```

[WorkflowBadge]: https://github.com/nsauzede/ns_hash/workflows/vade/badge.svg
[WorkflowUrl]: https://github.com/nsauzede/ns_hash/commits/main
