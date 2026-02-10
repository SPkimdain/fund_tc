//UNSAFE_JACKSON_DESERIALIZATION
package security;

import com.fasterxml.jackson.databind.ObjectMapper;
import org.codehaus.jackson.map.ObjectMapper;
import com.fasterxml.jackson.annotation.JsonTypeInfo;

public class UnsafeJacksonDeserialization {
    
    @JsonTypeInfo(use = Id.CLASS, include=As.WRAPPER_OBJECT) // @violation
    abstract class PhoneNumber {
    }

    @JsonTypeInfo(use = Id.MINIMAL_CLASS) // @violation
    abstract class PhoneNumber2 {
    }

    @JsonTypeInfo(use = Id.NAME) /* SAFE */
    abstract class PhoneNumber3 {
    }

    public void mapperTest() {
        ObjectMapper mapper = new ObjectMapper();
        mapper.enableDefaultTyping(); // @violation
    }

}