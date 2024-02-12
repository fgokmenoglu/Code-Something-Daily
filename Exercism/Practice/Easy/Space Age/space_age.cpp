#include "space_age.h"

namespace space_age {
    space_age::space_age(long long int seconds) : _seconds(seconds) {
    }
    
    long long int space_age::seconds() const {
        return _seconds;
    }

    double space_age::on_mercury() const {
        return (_seconds / 31557600.0) / 0.2408467;
    }

    double space_age::on_venus() const {
        return (_seconds / 31557600.0) / 0.61519726;
    }

    double space_age::on_earth() const {
        return _seconds / 31557600.0;
    }

    double space_age::on_mars() const {
        return (_seconds / 31557600.0) / 1.8808158;
    }

    double space_age::on_jupiter() const {
        return (_seconds / 31557600.0) / 11.862615;
    }

    double space_age::on_saturn() const {
        return (_seconds / 31557600.0) / 29.447498;
    }

    double space_age::on_uranus() const {
        return (_seconds / 31557600.0) / 84.016846;
    }

    double space_age::on_neptune() const {
        return (_seconds / 31557600.0) / 164.79132;
    }
}  // namespace space_age
