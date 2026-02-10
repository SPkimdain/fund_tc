package test.com.fasoo.javafinch.syn.rule.basic.classcast;

import java.util.List;

/**
 * CLASSCAST Test case 2 : Collection type defined
 * Collection의 세부 타입이 정의된 경우
 * @author JWYoon
 *
 */
public class ClassCast2 {
    class Shape {}
    class Triangle extends Shape {}

    List<Shape> shapeList;

    void addTriangle(Triangle t) {
        shapeList.add(t);
    }

    Triangle getTriangleFromShapeList() {
        return (Triangle)shapeList.get(0); // @violation
    }
}
