#pragma once

#include "warning_strategy.h"
#include "mild_warning.h"
#include "aggressivewarning.h"
#include "logger.h"

class StrategyFactory{

public:
    static WarningStrategy* createStrategy(const QString& mode){
        if(mode == "aggressive"){
            return new aggressiveWarning();
        }
        else if (mode == "mild"){
            return new mild_warning();
        }
        else{
            logger::getInstance()->log("UNkown strategy. Using default mild",
                                       Level::WARNING,
                                       "strategy factory",
                                       "STRAT - 001");
            return new mild_warning();
        }
    }
};
