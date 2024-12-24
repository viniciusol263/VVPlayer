#pragma once

#include <queue>
#include <optional>
#include <mutex>

namespace Libs
{
    template<typename T>
    class ThreadSafeQueue
    {
    public:
        ThreadSafeQueue() = default;
        
        void push(const T& value)
        {
            std::lock_guard lock(m_mutex);
            m_queue.push(value);
        }

        std::optional<T> pop()
        {
            std::lock_guard lock(m_mutex);
            if(m_queue.empty())
            {
                return std::nullopt;
            }
            auto value = m_queue.front();
            m_queue.pop();
            return value;
        }

        std::size_t size()
        {
            std::lock_guard lock(m_mutex);
            return m_queue.size();
        }

    private:
        std::queue<T> m_queue;
        std::mutex m_mutex;
    };
}