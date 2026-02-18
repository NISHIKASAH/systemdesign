#pragma once
#include <iostream>
#include<vector>
#include "./location.hpp"
#include "./enum.hpp"
using namespace std;

class Profile
{
    string name;
    int age;
    string bio;
    Location loc;
    vector<string>interests;
    vector<string>photos;
    GenderType gender;


public:
    Profile(string username, int g, string biodata , GenderType type)
    {
        name = username,
        age = g;
        bio = biodata;
        gender  = type; 

    }
    string getName(){
        return name;
    }
    int getAge(){
        return age;
    }

    int getLocation( int targetx , int targety){
        return loc.getDistanceinKm(targetx , targety);
    }
    GenderType getGender(){
        return gender;
    }
    void addInterest(string interest){
        interests.push_back(interest);

    }
    void addPhoto(string photo){
        photos.push_back(photo);
    }
    vector<string>getAllinterest(){
        return interests;
    }
    vector<string>getAllphoto(){
        return photos;
    }

};