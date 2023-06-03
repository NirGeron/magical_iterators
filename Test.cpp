#include "doctest.h"
#include "sources/MagicalContainer.hpp"


#include<iostream>
using namespace std;
using namespace ariel;



TEST_CASE("test prime func") {
    MagicalContainer container;
    container.addElement(67);
    container.addElement(29);
    container.addElement(22);
    container.addElement(12);
    container.addElement(2);
    MagicalContainer::SideCrossIterator ascIter(container);
    int arr[5]= {0};
    int i =0;
    for (auto it = ascIter.begin(); it != ascIter.end(); ++it,i++) {
       arr[0] =*it;
    }
    CHECK_EQ( arr[0], 2);
    CHECK_EQ( arr[1], 2);
    CHECK_EQ( arr[2],67);
}

TEST_CASE("general test") {
    
    MagicalContainer container;
    CHECK_NOTHROW(container.addElement(1));
    CHECK_NOTHROW(container.addElement(9));
    CHECK_NOTHROW(container.addElement(7));
    CHECK_NOTHROW(container.addElement(10));
    CHECK_NOTHROW(container.addElement(55));
    CHECK_NOTHROW(container.addElement(11));
    CHECK_NOTHROW(container.addElement(13));
int arr[] ={1,9,7,10,55};
int i =0;
   for (auto j :(container).getElement()) {
       CHECK_EQ(j,arr[i]);
       i++;
    }
    CHECK_EQ(container.size(),7);
    container.removeElement(55);
    CHECK_EQ(*container.getElement().end(),10);
}
TEST_CASE("test acending iterator sort") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);
    MagicalContainer::AscendingIterator ascIter(container);
    int arr[5]= {0};
    int i =0;
    for (auto j = ascIter.begin(); j != ascIter.end(); ++j,i++) {
       arr[i] =*j;
    }
    CHECK_EQ( arr[0], 1);
    CHECK_EQ( arr[1], 2);
    CHECK_EQ( arr[2],3);
    CHECK_EQ( arr[3], 4);
    CHECK_EQ( arr[4], 5);
}
TEST_CASE("test class - SideCrossIterator") {
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);
    MagicalContainer::SideCrossIterator SidIter(container);
    int arr[5]= {0};
    int i =0;
    for (auto it = SidIter.begin(); it != SidIter.end(); ++it,i++) {
       arr[0] =*it;
    }
    CHECK_EQ( arr[0], 2);
    CHECK_EQ( arr[1], 25);
    CHECK_EQ( arr[2], 3);
    CHECK_EQ( arr[3], 17);
    CHECK_EQ( arr[4], 9);


}
