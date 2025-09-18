# Market Maker Engine

A high-performance C++ implementation of an institutional-grade market making algorithm featuring dynamic spread adjustment, inventory management, adverse selection protection, and comprehensive risk controls.

## Strategy Overview

This project implements a **two-sided liquidity provision strategy** that:

- Continuously quotes **bid and ask prices** around current market price
- Captures **bid-ask spread** as profit when traders hit both sides
- Dynamically adjusts spreads based on **volatility, inventory, and market conditions**
- Manages inventory through **position skewing** to minimize directional risk
- Protects against **adverse selection** from informed traders
- Implements comprehensive **risk management** and position controls

### Example Trading Scenario
```
Stock trading at $100.00
├─ You quote: $99.98 bid, $100.02 ask (4¢ spread)
├─ Trader sells to you at $99.98 (you're now long)
├─ Adjust quotes: $99.99 bid, $100.01 ask (inventory skew)
├─ Trader buys from you at $100.01
└─ Profit: 3¢ per share captured
```

## 🏗️ Architecture

### Core Components

```
Market Maker Engine
├── MarketMaker          # Main orchestrator and decision engine
├── InventoryManager     # Position tracking and skew calculation  
├── SpreadCalculator     # Dynamic spread adjustment logic
├── AdverseSelectionFilter # Toxic flow detection and protection
├── OrderBook           # Fast market data structure
├── OrderManager        # Order lifecycle management
├── RiskManager         # Real-time P&L and risk controls
└── Utils               # Logging, config, and statistics
```

### Key Features

- **Dynamic Spread Adjustment**: Widens spreads during volatility, tightens in calm markets
- **Inventory Management**: Skews quotes to work back toward neutral position
- **Adverse Selection Protection**: Detects informed trading and adjusts accordingly
- **Risk Controls**: Position limits, P&L monitoring, circuit breakers
- **High Performance**: Lock-free data structures, memory pooling, microsecond latency
- **Comprehensive Testing**: Unit tests, integration tests, backtesting framework

## 🚀 Getting Started

### Prerequisites

```bash
# Required dependencies
- C++17 or later
- CMake 3.14+
- Boost libraries
- Eigen3 (linear algebra)
- nlohmann/json
- spdlog (logging)
- Google Test (testing)
```

### Building the Project

```bash
# Clone the repository
git clone https://github.com/yourusername/market-maker.git
cd market-maker

# Configure and build
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build

# Run tests
cd build && ctest
```

### Configuration

Edit `config/market_maker_config.json`:

```json
{
  "trading": {
    "symbols": ["AAPL", "MSFT", "GOOGL"],
    "base_spread_bps": 4,
    "max_position_size": 1000,
    "max_daily_loss": 10000
  },
  "risk": {
    "position_limit": 5000,
    "max_drawdown": 0.02,
    "volatility_lookback": 300
  }
}
```

### Running the Engine

```bash
# Start market maker with configuration
./build/market_maker --config config/market_maker_config.json

# Run with sample data
./build/market_maker --data data/sample_market_data.csv --backtest
```

## 📊 Development Roadmap

### Phase 1: Core Infrastructure ⏳
**Goal: Basic data flow and foundation**

- [ ] Order and Position data structures
- [ ] OrderBook implementation with price levels
- [ ] MarketDataHandler for tick data processing
- [ ] Configuration loading and logging setup
- [ ] Market data feed simulation
- [ ] Basic quote placement logic

### Phase 2: Market Making Logic 🔄
**Goal: Two-sided quoting system**

- [ ] Fixed spread calculation
- [ ] Volatility-based spread adjustment
- [ ] Mid-price calculation from order book
- [ ] Basic MarketMaker main loop
- [ ] Quote generation around mid-price

### Phase 3: Inventory Management 📈
**Goal: Smart position management**

- [ ] InventoryManager position tracking
- [ ] Inventory skew calculation
- [ ] Quote skewing based on position
- [ ] OrderManager lifecycle handling
- [ ] Position limit enforcement

### Phase 4: Risk & Protection 🛡️
**Goal: Loss prevention systems**

- [ ] Real-time P&L calculation
- [ ] Position and loss limits
- [ ] Adverse selection detection
- [ ] Market stress response
- [ ] Circuit breaker implementation

### Phase 5: Performance & Analytics 🚀
**Goal: Production optimization**

- [ ] Performance profiling and optimization
- [ ] Lock-free data structures
- [ ] Statistics collection and reporting
- [ ] Real-time monitoring dashboard
- [ ] Memory and latency optimization

### Phase 6: Testing & Validation ✅
**Goal: Reliability assurance**

- [ ] Comprehensive unit test suite
- [ ] Integration testing framework
- [ ] Historical data backtesting
- [ ] Stress testing scenarios
- [ ] Performance benchmarking

## 📈 Performance Metrics

Target performance characteristics:

| Metric | Target | Notes |
|--------|---------|--------|
| Order-to-Market Latency | < 100μs | Time to place quote after market update |
| Quote Update Frequency | > 1000/sec | Quotes per second processing capability |
| Memory Usage | < 100MB | Resident memory for single symbol |
| Fill Rate | 60-80% | Percentage of quotes that get filled |
| Sharpe Ratio | > 2.0 | Risk-adjusted returns in backtesting |

## 🧪 Testing

```bash
# Run all tests
cmake --build build --target test

# Run specific component tests  
./build/test_market_maker
./build/test_inventory_manager
./build/test_order_book

# Run backtesting
./build/backtest --data data/historical_data.csv --config config/backtest.json
```

## 📁 Project Structure

```
market-maker/
├── CMakeLists.txt                    # Build configuration
├── README.md                         # This file
├── config/
│   └── market_maker_config.json     # Strategy parameters
├── data/
│   └── sample_market_data.csv       # Sample market data
├── include/market_maker/             # Public headers
│   ├── market_maker.hpp             # Main engine interface
│   ├── inventory_manager.hpp        # Position management
│   ├── spread_calculator.hpp        # Dynamic spread logic
│   ├── adverse_selection_filter.hpp # Toxic flow protection
│   ├── order_book.hpp               # Market data structure
│   ├── order_manager.hpp            # Order lifecycle
│   ├── risk_manager.hpp             # Risk controls
│   └── utils/                       # Utilities
├── source/                          # Implementation files
│   ├── main.cpp                     # Entry point
│   ├── market_maker/                # Core algorithm
│   ├── market_data/                 # Market data processing
│   ├── orders/                      # Order management
│   ├── risk/                        # Risk management
│   └── utils/                       # Logging, config, stats
└── test/                            # Test suite
    └── source/                      # Unit and integration tests
```

## 🤝 Contributing

This is a portfolio project demonstrating quantitative finance and C++ engineering skills. Key areas of focus:

- **Mathematical Finance**: Options pricing, risk metrics, statistical arbitrage
- **High-Performance Computing**: Lock-free programming, memory optimization, SIMD
- **Market Microstructure**: Order book mechanics, market making, adverse selection
- **Software Engineering**: Modern C++, testing, documentation, architecture

## 📚 References & Learning Resources

- **Market Making Theory**: "Market Liquidity: Theory, Evidence, and Policy" by Foucault, Pagano, Röell
- **Algorithmic Trading**: "Algorithmic Trading: Winning Strategies and Their Rationale" by Chan
- **Market Microstructure**: "Trading and Exchanges" by Harris
- **C++ Performance**: "Optimized C++" by Halpern
- **Quantitative Finance**: "Paul Wilmott on Quantitative Finance" by Wilmott

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🏢 Professional Context

This project demonstrates skills relevant to roles at:
- **Market Making Firms**: Citadel Securities, Virtu Financial, Jump Trading
- **Quantitative Hedge Funds**: Renaissance Technologies, DE Shaw, Two Sigma  
- **Investment Banks**: Goldman Sachs (Electronic Trading), JP Morgan (Algorithmic Trading)
- **Proprietary Trading**: DRW, Optiver, IMC Trading

The implementation showcases understanding of:
- Real-time systems and low-latency programming
- Financial markets and trading strategies  
- Risk management and position control
- Modern C++ and software engineering practices

---

*Built with ❤️ for quantitative finance and high-performance computing*
