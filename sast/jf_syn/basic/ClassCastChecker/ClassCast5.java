package test.com.fasoo.javafinch.syn.rule.basic.classcast;

import java.util.Map;

/**
 * CLASSCAST Test case 5 : Map Collection: two parameters are required when put item
 * Map Collection에  대해서도 정상 동작 확인
 * @author JWYoon
 *
 */
public class ClassCast5 {
    class Shape {}
    class Triangle extends Shape {}

    @SuppressWarnings("rawtypes")
    Map shapeMap;

    @SuppressWarnings("unchecked")
    void addShape(String key, Shape s) {
        shapeMap.put(key, s);
    }

    Triangle getTriangleFromShapeMap(String key) {
        return (Triangle)shapeMap.get(key); // @violation
    }
}
