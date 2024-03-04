#include "subject.hpp"

bool Subject::attach(Observer *obs) {
    auto [pos, success] = m_obs.insert(obs);
    return success;
}

bool Subject::detach(Observer *obs) {
    // if (auto pos = m_obs.find(obs); pos != m_obs.end()) {
    //     m_obs.erase(pos);
    // }
    return m_obs.erase(obs) > 0U;
}

void Subject::notify() {
    for(auto& obs : m_obs) {
        obs->update(*this);
    }
}