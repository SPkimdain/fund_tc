package test.com.fasoo.javafinch.syn.rule.basic.classcast;

import java.util.List;

/**
 * CLASSCAST Test case 6 : No relationship between class types
 * Element의 타입과 Casting 하는 타입간의 계층적 연관성이 없는 경우
 * @author JWYoon
 *
 */
public class ClassCast6 {
    class Book {}
    class Dog {}

    @SuppressWarnings("rawtypes")
    List list;

    @SuppressWarnings("unchecked")
    void addBook(Book b) {
        list.add(b);
    }

    @SuppressWarnings("unchecked")
    void addRectangle(Dog d) {
        list.add(d);
    }

    Book getBook() {
        return (Book)list.get(0); // @violation
    }

    Dog getDog() {
        return (Dog)list.get(0); // @violation
    }
}
