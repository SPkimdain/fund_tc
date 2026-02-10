package testcase.rule.security.DeserializationOfUntrustedDataChecker

import com.esotericsoftware.kryo.Kryo
import com.fasterxml.jackson.annotation.JsonTypeInfo
import com.fasterxml.jackson.databind.ObjectMapper
import org.apache.commons.io.serialization.ValidatingObjectInputStream
import org.nibblesec.tools.SerialKiller
import java.beans.XMLDecoder
import java.io.*
import javax.servlet.ServletInputStream
import javax.servlet.http.HttpServletRequest

object TestCase {
	fun violation1() {
		val mapper = ObjectMapper()
		mapper.enableDefaultTyping()							// @violation
	}

	fun violation2() {
		val input = BufferedInputStream(FileInputStream("C:\\Sample.xml"))
		val decoder = XMLDecoder(input)
		val result = decoder.readObject()						// @violation
		// ...
		decoder.close()
	}

	fun violation3(request: HttpServletRequest) {
		val servletInputStream = request.inputStream
		val objectInputStream = ObjectInputStream(servletInputStream)
		val obj = objectInputStream.readObject()				// @violation
	}

    fun violation4() {
        Kryo().setRegistrationRequired(false)       // @violation
        Kryo().isRegistrationRequired = false       // @violation
        Kryo().apply {
            isRegistrationRequired = false          // @violation
        }
    }

	@JsonTypeInfo(use = JsonTypeInfo.Id.CLASS)					// @violation
	abstract class Violation4 {
		// ...
	}

	@JsonTypeInfo(use = JsonTypeInfo.Id.MINIMAL_CLASS)			// @violation
	abstract class Violation5 {
		// ...
	}

	class SecureObjectInputStream(servletInputStream: ServletInputStream): ObjectInputStream(servletInputStream) {
		@Throws(IOException::class, ClassNotFoundException::class)
		override fun resolveClass(osc: ObjectStreamClass): Class<*> {
			// Only deserialize instances of AllowedClass
			if (osc.name != AllowedClass::class.java.name) {
				throw InvalidClassException("Unauthorized deserialization", osc.name)
			}
			return super.resolveClass(osc)
		}
	}

	fun good1(request: HttpServletRequest) {
		val servletInputStream = request.inputStream
		val secureObjectInputStream = SecureObjectInputStream(servletInputStream)
		val obj = secureObjectInputStream.readObject()			// good
	}

	fun good2(request: HttpServletRequest) {
		val servletInputStream = request.inputStream
		val serialKiller = SerialKiller(servletInputStream, "/etc/serialkiller.conf")
		val obj = serialKiller.readObject()						// good
	}

	fun good3(request: HttpServletRequest) {
		val servletInputStream = request.inputStream
		val validatingObjectInputStream: ValidatingObjectInputStream = ValidatingObjectInputStream(servletInputStream)
		val obj = validatingObjectInputStream.readObject()		// good
	}

	@JsonTypeInfo(use = JsonTypeInfo.Id.NAME)					// good
	abstract class Good4 {
		// ...
	}
}