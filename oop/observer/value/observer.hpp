#pragma once
#include <functional>

template <typename Subject, typename StateTag> class Observer {
public:
  using OnUpdate = std::function<void(const Subject &sub, StateTag state)>;
  explicit Observer(OnUpdate func) : func_m{std::move(func)} {}
  void update(const Subject &sub, StateTag state) { func_m(sub, state); }

private:
  OnUpdate func_m;
};