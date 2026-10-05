#include "../include/utils.h"

namespace DND_GM_Helper_5E {
namespace Utils {

Utils::Utils() {}

int Utils::Rand_int(int Min , int Max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(Min, Max);

    int random = distrib(gen);
    return random;
}

} // namespace Utils
} // namespace DND_GM_Helper_5E
