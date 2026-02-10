package test.com.fasoo.javafinch.syn.rule.basic.classcast;

import java.util.List;

/**
 * CLASSCAST Test case 1 : Simple CLASSCAST
 * 기본적인 CLASSCAST 오류 검출
 * @author JWYoon
 *
 */
public class ClassCast1 {
    class Shape {}
    class Triangle extends Shape {}

    @SuppressWarnings("rawtypes")
    List shapeList;
    @SuppressWarnings("rawtypes")
    List triangleList;

    @SuppressWarnings("unchecked")
    void addShape(Shape s) {
        shapeList.add(s);
    }

    @SuppressWarnings("unchecked")
    void addTriangle(Triangle t) {
        triangleList.add(t);
    }

    Triangle getTriangleFromShapeList() {
        return (Triangle)shapeList.get(0); // @violation
    }

    Triangle getTriangleFromTriangleList() {
        return (Triangle)triangleList.get(0); // Not bug
    }
}
