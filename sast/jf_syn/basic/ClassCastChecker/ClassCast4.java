package test.com.fasoo.javafinch.syn.rule.basic.classcast;

import java.util.List;

/**
 * CLASSCAST Test case 4 : Multi children
 * 자식 클래스가 여러 개 일 경우 정상 동작 확인
 * @author JWYoon
 *
 */
public class ClassCast4 {
    class Shape {}
    class Triangle extends Shape {}
    class Rectangle extends Shape {}

    @SuppressWarnings("rawtypes")
    List shapeList;

    @SuppressWarnings("unchecked")
    void addTriangle(Triangle t) {
        shapeList.add(t);
    }

    @SuppressWarnings("unchecked")
    void addRectangle(Rectangle r) {
        shapeList.add(r);
    }

    Triangle getTriangleFromShapeList() {
        return (Triangle)shapeList.get(0); // @violation
    }

    Rectangle getRectangleFromShapeList() {
        return (Rectangle)shapeList.get(0); // @violation
    }
}
