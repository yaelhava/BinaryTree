/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using std::cout, std::endl;
#include "badkan.hpp"
#include "Tree.hpp"

int main() {
  ariel::Tree emptytree;
  ariel::Tree threetree;  
  ariel::Tree testtree;
  
  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);
  
  testtree.insert(3).insert(2).insert(4).insert(12).insert(11).insert(32)
          .insert(5).insert(-32).insert(1).insert(14).insert(-10);


  ariel::Tree mytree;  
    
  
  badkan::TestCase tc("Binary tree");
  tc
  .CHECK_EQUAL (emptytree.size(), 0)
  .CHECK_OK    (emptytree.insert(5))
  .CHECK_EQUAL (emptytree.size(), 1)
  .CHECK_EQUAL (emptytree.contains(5), true)
  .CHECK_OK    (emptytree.remove(5))
  .CHECK_EQUAL (emptytree.contains(5), false)
  .CHECK_THROWS(emptytree.remove(5))
  .CHECK_EQUAL (emptytree.size() ,0)
  .CHECK_THROWS(emptytree.root())
  .CHECK_OK(emptytree.insert(17))
  .CHECK_EQUAL(emptytree.root(), 17)
  .CHECK_THROWS(emptytree.parent(17))
  .CHECK_THROWS(emptytree.left(17))
  .CHECK_THROWS(emptytree.right(17))
  .CHECK_OK(emptytree.insert(10))
  .CHECK_EQUAL(emptytree.left(17), 10)
  .CHECK_OK(emptytree.insert(100))
  .CHECK_OK(emptytree.insert(26))
  .CHECK_EQUAL(emptytree.size(), 4)
  .CHECK_THROWS(emptytree.left(10))
  .CHECK_THROWS(emptytree.right(100))
  .CHECK_OK(emptytree.remove(100))
  .CHECK_OK(emptytree.remove(17))
  .CHECK_EQUAL(emptytree.size(), 2)
  .CHECK_OK(emptytree.print())
  .print()
  
  .CHECK_EQUAL (threetree.size(), 3)
  .CHECK_EQUAL (threetree.root(), 5)
  .CHECK_EQUAL (threetree.parent(3), 5)
  .CHECK_EQUAL (threetree.parent(7), 5)
  .CHECK_EQUAL (threetree.left(5), 3)
  .CHECK_EQUAL (threetree.right(5), 7)
  .CHECK_THROWS(threetree.insert(3))
  .CHECK_THROWS(threetree.left(6))
  .CHECK_OK(threetree.insert(26))
  .CHECK_OK(threetree.insert(4))
  .CHECK_EQUAL(threetree.contains(8),false)
  .CHECK_EQUAL(threetree.size(), 5)
  .CHECK_OK(threetree.remove(7))
  .CHECK_THROWS(threetree.left(7))
  .CHECK_EQUAL(threetree.size(), 4)
  .CHECK_EQUAL (threetree.parent(26), 5)
  .CHECK_OK(threetree.remove(26))
  .CHECK_EQUAL(threetree.size(), 3)
  .CHECK_EQUAL(threetree.contains(26),false)
  .CHECK_EQUAL (threetree.parent(4), 3)
  .CHECK_THROWS(threetree.left(3))
  .CHECK_EQUAL (threetree.right(3), 4)
  .CHECK_OK    (threetree.print())
  .print()
  
  .CHECK_EQUAL(testtree.contains(32), true)
  .CHECK_EQUAL(testtree.size(), 11)
  .CHECK_EQUAL(testtree.root(), 3)
  .CHECK_THROWS(testtree.insert(3))
  .CHECK_EQUAL(testtree.parent(12), 4)
  .CHECK_EQUAL(testtree.left(12), 11)
  .CHECK_EQUAL(testtree.right(3), 4)
  .CHECK_THROWS(testtree.parent(3))
  .CHECK_OK(testtree.remove(5))
  .CHECK_OK(testtree.remove(12))
  .CHECK_THROWS(testtree.left(11))
  .CHECK_OK(testtree.print())
   .CHECK_OK(testtree.remove(3))
  .CHECK_EQUAL(testtree.size(),8)
  .CHECK_OK(testtree.insert(17))
  .CHECK_EQUAL(testtree.left(2), -32)
  .CHECK_EQUAL(testtree.parent(1), -32)
   .CHECK_EQUAL(testtree.contains(18), false)
  .CHECK_THROWS(testtree.remove(13))
  .CHECK_THROWS(testtree.left(-32))
  .CHECK_THROWS(testtree.right(5))
  .CHECK_EQUAL(testtree.contains(-10), true)
  .CHECK_OK(testtree.print())
  .print()

  
  ;
  
  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}
