#ifndef ASSET_HPP
#define ASSET_HPP

#include <string>

namespace chants {

class Asset {
public:
    Asset(const std::string& name, const std::string& message, int value, bool isOffensive);

    std::string GetName() const;
    std::string GetMessage() const;
    int GetValue() const;
    bool IsOffensive() const;

private:
    std::string name;
    std::string message;
    int value;
    bool isOffensive;
};

} // namespace chants

#endif // ASSET_HPP
