#include <benchmark/benchmark.h>

#include <MaxPool2D.h>
#include <Threads.h>
#include <Types.h>

static void BM_MaxPool2D_224x224x64_2x2(benchmark::State &state)
{
    constexpr int SIZE = 224, CHANNELS = 64;
    auto psrc = new int8_t[SIZE * SIZE * CHANNELS];
    npuemulator::Tensor src(psrc, SIZE, SIZE, CHANNELS);
    auto pdst = new int8_t[SIZE / 2 * SIZE / 2 * CHANNELS];
    npuemulator::Tensor dst(pdst, SIZE / 2, SIZE / 2, CHANNELS);
    for (auto _ : state) {
        npuemulator::MaxPool2D(src, 2, 2, {2, 2}, {0, 0, 0, 0}, dst);
    }
    delete[] psrc;
    delete[] pdst;
}
//BENCHMARK(BM_MaxPool2D_224x224x64_2x2)->Iterations(200)->Unit(benchmark::TimeUnit::kMillisecond);
