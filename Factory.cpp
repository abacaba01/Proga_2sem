#include <unordered_map>
#include <string>
#include <functional>
#include <iostream>

template <class TBaseProduct>
class Factory {
private:
    std::unordered_map<std::string, std::function<TBaseProduct *()>> a;
    Factory() = default;
    Factory(const Factory &) = delete;
    Factory(Factory &&) = delete;
    Factory &operator=(const Factory &) = delete;
    Factory &operator=(Factory &&) = delete;
public:
    static Factory &Get() {
        static Factory inst;
        return inst;
    }
    static auto *Make(const std::string &name) {
        return Factory<TBaseProduct>::Get().a[name]();
    };
    static auto Register(const std::string &name, std::function<TBaseProduct*()> creator) {
        Factory<TBaseProduct>::Get().a[name] = creator;
        return true;
    };
};

class Dota {
public:
    virtual void Print() = 0;
};

static Factory<Dota>& factory = Factory<Dota>::Get();

#define PROD_PROLOGUE(Base, Child, Phrase)     \
    class Child : public Base {                \
    private:                                   \
         std::string a = Phrase;               \
    public:                                    \
        void Print() {                         \
        std::cout << a;}                       \
        static Base* Make() {                  \
        return new Child;}                     \
    };                                         \

#define PROD_REGISTER(Base, Child, Child_Name, Child_Register) \
namespace { \
static bool Child_Register = Factory<Base>::Register(Child_Name, Child::Make); \
};

PROD_PROLOGUE(Dota, Pudge, "chinchopachinchopa")
PROD_REGISTER(Dota, Pudge, "Pudge", Pudge_Register)

int main() {
    auto p = Factory<Dota>::Make("Pudge");
    p->Print();
    delete p;
    return 0;
}


