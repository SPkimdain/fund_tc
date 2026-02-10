package testcase.rule.quality.UnsafeSingletonChecker

import kotlin.jvm.Synchronized
import org.antlr.v4.runtime.ParserRuleContext

class ClassName private constructor() {
    companion object {
        private var instance: ClassName? = null

        fun getInstance(): ClassName {      // @violation
            if (instance == null) {
                instance = ClassName()
            }
            return instance!!
        }
    }
}

class ClassNameSafe private constructor() {
    companion object {
        private var instance: ClassNameSafe? = null

        @Synchronized
        fun getInstance(): ClassNameSafe {      // safe: annotation
            if (instance == null) {
                instance = ClassNameSafe()
            }
            return instance!!
        }
    }
}

class ClassNameSafe2 private constructor() {
    companion object {
        private var instance: ClassNameSafe2? = null

        fun getInstance(): ClassNameSafe2 {      // safe: synchronized block
            synchronized(this) {
                if (instance == null) {
                    instance = ClassNameSafe2()
                }
                return instance!!
            }
        }
    }
}

class NodeHandler private constructor(context: ParserRuleContext) {
    companion object {
        private var instance: NodeHandler? = null

        fun getInstance(context: ParserRuleContext): NodeHandler {      // OK: not singleton instnace
            return instance ?: NodeHandler(context).also {
                instance = it
            }
        }
    }
}