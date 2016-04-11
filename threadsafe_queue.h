#include <memory>
#include <queue>
#include <mutex>
#include <condition_variable>

template <typename T>
class threadsafe_queue {
  mutable std::mutex m_mtx;
  std::condition_variable m_cv;
  std::queue<std::shared_ptr<T>> m_queue;
public:
  threadsafe_queue() {}
  
  void wait_and_pop(T& value);
  std::shared_ptr<T> wait_and_pop();
  
  bool try_pop(T& value);
  std::shared_ptr<T> try_pop();
  
  void push(T new_value);
  
  bool empty() const;
};
