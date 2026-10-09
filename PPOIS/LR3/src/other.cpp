#include "other.hpp"

bool Tower::needsRepair() {
    for (auto* s : sensors) {
        if (s != nullptr && !s->isValid()) return true;
    }
    return false;
}

int Tower::getSensorCount() {
    return sensors.size();
}

bool MaintenanceTask::isOverdue() {
    return !completed;
}