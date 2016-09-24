import qbs

CppApplication {
    consoleApplication: true
    files: "main.cpp"
    cpp.cxxLanguageVersion: "c++14"
    cpp.cxxFlags: "-fconcepts"

    Group {     // Properties for the produced executable
        fileTagsFilter: product.type
        qbs.install: true
    }
}
