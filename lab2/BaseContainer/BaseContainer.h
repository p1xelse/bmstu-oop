#include <cstddef>

class BaseContainer {
 public:
    virtual bool empty() const;
    virtual void clear() = 0;
    virtual ~BaseContainer() = default;

 protected:
    size_t size = 0;
};
