#ifndef MAGICALCONTAINER_HPP
#define MAGICALCONTAINER_HPP

#include <algorithm>
#include<iostream>
#include <functional>
#include <stdexcept>
#include <vector>


using namespace std;
namespace ariel{
class MagicalContainer {
    private:
        vector<int> elements;
    public:
        vector<int> getElement();
        int size();
        void addElement(int e);
        void removeElement(int e);
        bool check_if_prime(int num);
    
    class AscendingIterator {
        public:
            AscendingIterator(MagicalContainer* c, int i);
            AscendingIterator(MagicalContainer& c);
            bool operator>(const AscendingIterator& iterator) const;
            bool operator<(const AscendingIterator& iterator) const;
            bool operator==(const AscendingIterator& iterator) const;
            bool operator!=(const AscendingIterator& iterator) const;
            AscendingIterator begin();
            AscendingIterator end();
            AscendingIterator& operator++();
            AscendingIterator& operator<<(int paces);
            AscendingIterator& operator>>(int paces);
            int operator*() const;
            void sort(MagicalContainer*);
        
        private:
            MagicalContainer* container;
            int curr_index;

    };

    class SideCrossIterator {
        public:
            SideCrossIterator begin();
            SideCrossIterator end();
            bool operator==(const SideCrossIterator& iterator) const;
            bool operator!=(const SideCrossIterator& iterator) const;
            bool operator>(const SideCrossIterator& iterator) const;
            bool operator<(const SideCrossIterator& iterator) const;
            SideCrossIterator();
            SideCrossIterator(MagicalContainer* c, int index, int direction);
            SideCrossIterator(MagicalContainer& c);
            int operator*() const;
            SideCrossIterator& operator++();
            SideCrossIterator& operator<<(int paces);
            SideCrossIterator& operator>>(int paces);


        private:
            MagicalContainer* container;
            int curr_index;
            int direction;    
    };

    class PrimeIterator {
        public:
            PrimeIterator();
            PrimeIterator(MagicalContainer* c, int index);
            PrimeIterator(MagicalContainer& c);
            int operator*() const;
            bool operator==(const PrimeIterator& iterator) const;
            bool operator!=(const PrimeIterator& iterator) const;
            bool operator>(const PrimeIterator& iterator) const;
            bool operator<(const PrimeIterator& iterator) const;
            PrimeIterator& operator++();
            PrimeIterator& operator<<(int paces);
            PrimeIterator& operator>>(int paces);


        PrimeIterator begin();
        PrimeIterator end();
        private:
            MagicalContainer* container;
            int curr_index;
    };
};

}
#endif 