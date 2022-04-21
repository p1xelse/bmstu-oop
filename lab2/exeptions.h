#include <exception>
#include <string>

class SetException : public std::exception {
 public:
    SetException(const std::string &time, const std::string &filename,
                 const std::string &classname, const std::string &method) {
        exeptionMsg = "\nTime: " + time + "\tFile: " + filename +
                      "\n\tClass: " + classname + "\n\tMethod: " + method;
    }

    const char *what() const noexcept override { return exeptionMsg.c_str(); }

 protected:
    std::string exeptionMsg;
};

class BadAllocateMemory : public SetException {
 public:
    BadAllocateMemory(const std::string &time, const std::string &filename,
                      const std::string &classname, const std::string &method)
        : SetException(time, filename, classname, method) {
        std::string allocMsg = "\n ERROR: Allocate memory:\n";
        exeptionMsg = allocMsg + exeptionMsg;
    }
};

class IteratorExeption : public SetException {
 public:
    IteratorExeption(const std::string &time, const std::string &filename,
                     const std::string &classname, const std::string &method)
        : SetException(time, filename, classname, method) {
        std::string iteratorMsg = "\n ERROR: Invalid iterator:\n";
        exeptionMsg = iteratorMsg + exeptionMsg;
    }
};
