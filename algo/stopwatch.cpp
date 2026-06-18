class stopwatch
{
    std::chrono::time_point<std::chrono::system_clock, std::chrono::duration<double> > time;
public:
    stopwatch () {time = std::chrono::high_resolution_clock::now(); }
    ~stopwatch()
    {
        std::chrono::duration<double> duration = std::chrono::high_resolution_clock::now() - time;
        std::cout << duration.count() << endl;
    }
};  