        //constructors used in the same order as described above:
        // ft::Vector<int> first;                                // empty Vector of ints
        // ft::Vector<int> second (4,100);    
        // ft::Vector<int>::iterator it1,it2;                   // four ints with value 100
        // it1 = second.begin();

        // it2 = second.end();
        // int *f1 = &(*it1);
        // int *f2 = &(*it2);


        // ft::Vector<int> third (f1,f2); // iterating through second
        // ft::Vector<int> fourth (third);                     // a copy of third

        // // the iterator constructor can also be used to construct from arrays:
        // int myints[] = {16,2,77,29};
        // ft::Vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

        // std::cout << "The contents of third are:";
        // for (ft::Vector<int>::iterator it = third.begin(); it != third.end(); ++it)
        //     std::cout << ' ' << *it;
        // std::cout << '\n';