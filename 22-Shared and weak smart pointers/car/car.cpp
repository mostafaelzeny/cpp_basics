#include "car.h"
#include "v7Engine.h"
#include "v8Engine.h"
#include "IEngine.h"

Car::Car(std::unique_ptr<IEngine>&& engine) : m_engine(std::move(engine))
{
}

void Car::Drive()
{
    m_engine->Start();
    //Drive
}
void Car::Stop()
{
    m_engine->Stop();
}

int main()
{
    std::unique_ptr<V7Engine> engine_v7 = std::make_unique<V7Engine>();
    Car MiniCoper(move(engine_v7));  //Dependency Injection
    MiniCoper.Drive();

    Car BMW_E36(std::move(MakeV8Engine()));  //Dependency Injection
    BMW_E36.Drive();
    BMW_E36.Stop();
    
    return 0;
}