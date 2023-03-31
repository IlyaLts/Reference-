#include <iostream>
#include <coroutine>

// co_yield - Completes execution returning a value
// co_return - Suspends execution returning a value
// co_await - Suspends execution until resumed

// std::suspend_always
// std::suspend_never

// yield_value
// 
// get_return_object
// return_void
// unhandled_exception

// initial_suspend  
// final_suspend

using namespace std;

// The caller-level type
struct Future
{
    // The coroutine level type
    struct Promise
	{
        Future get_return_object() { cout << "get_return_object()\n"; return {}; }
        std::suspend_never initial_suspend() { cout << "initial_suspend()\n"; return {}; }
        std::suspend_never final_suspend() noexcept { cout << "final_suspend()\n"; return {}; }
        void return_void() { cout << "return_void()\n"; }
        void unhandled_exception() { cout << "unhandled_exception()\n"; }
    };
};
Future myCoroutine()
{
    co_return; // make it a coroutine
}
int main() {
    Future x = myCoroutine();
}

/*
template <typename T>
class Future
{
    class Promise
    {
    public:
        using value_type = std::optional<T>;
		
        Promise() = default;
        std::suspend_always initial_suspend() { return {}; }
        std::suspend_always final_suspend() noexcept { return {}; }
        void unhandled_exception() { 
            std::rethrow_exception(std::move(std::current_exception())); 
        }

        std::suspend_always yield_value(T value) {
            this->value = std::move(value);
            return {};
        }

        void return_void() {
            this->value = std::nullopt;
        }

        inline Future get_return_object()

        value_type get_value() {
            return value;
        }

    private:
        value_type value{};
    };
};

*/