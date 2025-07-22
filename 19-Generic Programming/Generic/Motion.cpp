#include <iostream>

template<typename T>

class Sensor
{
    public:
    virtual T*  Read() = 0;

};


class Motion
{
    public:
    Motion():x(0), y(0), z(0)
    {

    }
    Motion(double x_, double y_, double z_):x(x_), y(y_), z(z_)
    {

    }

    double getx()
    {
        return this->x;
    }
    double gety()
    {
        return this->y;
    }
    double getz()
    {
        return this->z;
    }

    void setx(double new_x)
    {
        this->x = new_x ;
    }
    void sety(double new_y)
    {
        this->y = new_y ;
    }
    void setz(double new_z)
    {
        this->z = new_z ;
    }

    private:
    double x;
    double y;
    double z;

};
class Accelorometer : public Sensor<Motion >
{
    public:
    Accelorometer()
    {
        std::cout<< " Motion Initialized"<<std::endl;
    }

    Motion* Read() override
    {
        data = new Motion(5, 7.8, 3);
        return data;
    }

    

    void noisefilter()
    {
        data->setx(15);
        data->sety(30);
        data->setz(45);
        std::cout<<data->getx()<<" "<<data->gety()<<" "<<data->getz()<<std::endl;

    }



    private:
    Motion *data;

   

};

void processing_sensor(Accelorometer& acc)
{
     Motion *data = acc.Read();
     std::cout<<data->getx()<<" "<<data->gety()<<" "<<data->getz()<<std::endl;
}




int main()
{

    Accelorometer acc;

    processing_sensor(acc);
    acc.noisefilter();
    


    return 0;
}