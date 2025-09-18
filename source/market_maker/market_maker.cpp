// source/market_maker/market_maker.cpp
#include "market_maker/market_maker.hpp"
#include <iostream>

namespace market_maker {
    void MarketMaker::start() {
        std::cout << "Market maker starting..." << std::endl;
    }
    
    void MarketMaker::stop() {
        std::cout << "Market maker stopping..." << std::endl;
    }
}
