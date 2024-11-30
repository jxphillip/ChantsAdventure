#include "Asset.hpp"

namespace chants {

Asset::Asset(const std::string& name, const std::string& message, int value, bool isOffensive)
    : name(name), message(message), value(value), isOffensive(isOffensive) {}

std::string Asset::GetName() const {
    return name;
}

std::string Asset::GetMessage() const {
    return message;
}

int Asset::GetValue() const {
    return value;
}

bool Asset::IsOffensive() const {
    return isOffensive;
}

} // namespace chants
