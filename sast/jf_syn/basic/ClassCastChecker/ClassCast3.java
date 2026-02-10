package test.com.fasoo.javafinch.syn.rule.basic.classcast;

import java.util.List;

/**
 * CLASSCAST Test case 3 : Multi-level inheritance
 * 타입 클래스들이 여러 계층으로 상속이 이루어 질 경우 정상 동작 확인
 * @author JWYoon
 *
 */
public class ClassCast3 {
    class Shape {}
    class Triangle extends Shape {}
    class RightTriangle extends Triangle {}

    @SuppressWarnings("rawtypes")
    List shapeList;

    @SuppressWarnings("unchecked")
    void addShape(Shape s) {
        shapeList.add(s);
    }

    Triangle getTriangleFromShapeList() {
        return (Triangle)shapeList.get(0); // @violation
    }

    RightTriangle getRightTriangleFromShapeList() {
        return (RightTriangle)shapeList.get(0); // @violation
    }
}