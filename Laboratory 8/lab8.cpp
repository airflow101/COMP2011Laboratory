#include "lab8.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <limits>

using namespace std;


void load_robots(Robot robots[], int* num_robots, string filename)
{
    int id;
    Location location;
    ifstream ifs(filename);
    if (ifs.fail()){
        cout << "Fail in loading txt files" << endl;
        return; }
    //while (!ifs.eof()) {
    while(ifs >> id >> location.x >> location.y){
        add_new_robot(robots, num_robots, id, location);
    }
    ifs.close();
}


bool add_new_robot(Robot robots[], int *num_robots, int id, Location location)
{
    //TODO: implemente this function
    robots[*num_robots].id = id;
    robots[*num_robots].location = location;
    robots[*num_robots].package = nullptr;
    (*num_robots)++;
    return true;

}

void load_packages(Package packages[], int *num_packages, string filename)
{
    int id;
    Location location, destination;
    ifstream ifs(filename);
    if (ifs.fail()){
        cout << "Fail in loading txt files" << endl;
        return; }
    //while (!ifs.eof()) {
    while(ifs >> id >> location.x >> location.y >> destination.x >> destination.y){
        add_new_package(packages, num_packages, id, location, destination);
    }
    ifs.close();
}



bool add_new_package(Package packages[], int * num_packages, int id, Location location, Location destination)
{
    //TODO: implemente this function
    packages[*num_packages].id = id;
    packages[*num_packages].location = location;
    packages[*num_packages].destination = destination;
    packages[*num_packages].carrier = nullptr;
    packages[*num_packages].is_delivered = false;
    (*num_packages)++;
    return true;

}



Package * query_packages_information_by_id(Package packages[], int num_packages, int id)
{
    for (int i = 0; i < num_packages; ++i) {
        if (packages[i].id == id) {
            return &(packages[i]);
        }
    }
    return nullptr;
}


Robot * query_robots_information_by_id(Robot robots[], int num_robots, int id)
{
    for (int i = 0; i < num_robots; ++i) {
        if (robots[i].id == id) {
            return &(robots[i]);
        }
    }
    return nullptr;
}


void print_package_information(const Package * package)
{
    cout << "Package id: " << setw(3) << package->id << endl;
    cout << "Location: " << package->location.x << ", " << package->location.y<< endl;
    cout << "Destination: " << package->destination.x << ", " << package->destination.y<< endl;
    cout << "Is deliveried?: " << package->is_delivered << endl;
    if (package->carrier == nullptr)
        cout << "Carrier: nullptr" << endl;
    else
        cout << "Carrier id: " << package->carrier->id << endl;
    cout << '\n';
}

void print_robot_information(const Robot * robot)
{
    cout << "Robot id: " << setw(3) << robot->id << endl;
    cout << "Location: (" << robot->location.x << ", " << robot->location.y << ")\n";
    if (robot->package == nullptr){
        cout << "Package loaded: nullptr" << endl;
    }else{
        cout << "Package loaded: id " << robot->package->id <<endl;
    }
    cout << '\n';
}


double euclidean_distance(const Location * l1, const Location * l2)
{
    double x_diff = l1->x - l2->x;
    double y_diff = l1->y - l2->y;
    return sqrt(x_diff * x_diff + y_diff * y_diff);
}



Robot* find_nearest_robot(Package package, Robot robots[], int num_robots)
{
    //TODO: implemente this function
    //you can use the euclidean_distance function.
    int shortest_distance_robot = 0;
    for(int i = 0; i < num_robots; i++){
      if(euclidean_distance(&(robots[i].location), &(package.location)) < euclidean_distance(&(robots[shortest_distance_robot].location), &(package.location)))
        shortest_distance_robot = i;
    }
    return &(robots[shortest_distance_robot]);

}

Package* find_nearest_undeliver_package(Robot robot, Package packages[], int num_packages)
{
    //TODO: implemente this function. Note: find the nearest package that is NOT delivered yet.
    //you can use the euclidean_distance function.
    int shortest_distance_package = 0;
    for(int i = 0; i < num_packages; i++){
      if(euclidean_distance(&(packages[i].location), &(robot.location)) < euclidean_distance(&(packages[shortest_distance_package].location), &(robot.location)) && !(packages[i].is_delivered))
        shortest_distance_package = i;
    }
    return &(packages[shortest_distance_package]);

}

bool assign_one_delivery_task(Package *package, Robot *robot)
{
  robot->package = package;
  package->carrier = robot;
  return true;
}

void update_state_upon_delivery_finished(Package *package, Robot *robot){
    package->is_delivered = true;
    package->location = package->destination;

    robot->location = package->destination;
    robot->package = nullptr;
}

int delivery_one_package(Package *package, Robot robots[], int num_robots)
{
    Robot *nearest_robot = nullptr;

    nearest_robot = find_nearest_robot(*package, robots, num_robots);
    if (assign_one_delivery_task(package, nearest_robot)){
        //assume that the delivery is done in a moment
        update_state_upon_delivery_finished(package, nearest_robot);
        return nearest_robot->id;

    }else{
        return -1;
    }

}

int generate_delivery_order_for_one_robot(Robot robot, Package packages[], int num_packages, int deliver_order[]){
    // count the number of packages that are not delivered yet
    int require_delivery = 0;
    for(int i = 0; i < num_packages; i++){
      if(!packages[i].is_delivered){
        require_delivery++;
      }
    }

    for(int i = 0; i < require_delivery; i++){
        Package *temp_package = find_nearest_undeliver_package(robot, packages, num_packages);
        deliver_order[i] = temp_package->id;
        robot.location = temp_package->destination;
        temp_package->is_delivered = true;
      }

    return require_delivery;    }

void deliver_packages_with_one_robot(Robot *robot, Package packages[], int num_packages)
{
    int deliver_order[MAX_PACKAGES]={0};
    int num_delivery = 0;

    num_delivery = generate_delivery_order_for_one_robot(*robot, packages, num_packages, deliver_order);

    for (int i=0; i<num_delivery; i++){
        Package *package=nullptr;
        int package_id = deliver_order[i];

        package = query_packages_information_by_id(packages, num_packages, package_id);
        // delivery and update the package state
        assign_one_delivery_task(package, robot);
        update_state_upon_delivery_finished(package, robot);
    }

    cout << "Finish delivering all packages. Delivery order: " << endl;

    for (int i=0; i<num_delivery; i++){
        cout << "\t" << deliver_order[i];
    }
    cout << endl;
}
