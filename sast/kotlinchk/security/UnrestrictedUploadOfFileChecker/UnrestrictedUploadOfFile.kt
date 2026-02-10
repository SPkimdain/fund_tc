package testcase.rule.security.UnrestrictedUploadOfFileChecker

import org.apache.commons.fileupload.FileItem
import org.apache.commons.fileupload.FileUpload
import org.springframework.web.bind.annotation.PostMapping
import org.springframework.web.bind.annotation.RequestParam
import org.springframework.web.multipart.MultipartFile
import java.io.File
import java.io.IOException
import java.nio.file.Files
import java.nio.file.Paths
import javax.servlet.http.HttpServletRequest

object TestCase {
	 @PostMapping("/upload1")
	 fun violation1(@RequestParam("file") file: MultipartFile): String {						// 외부입력
	 	val rootLocation = Paths.get("storage")
	 	val fileName = file.originalFilename

	 	if(fileName != null) {
	 		Files.copy(file.inputStream, rootLocation.resolve(fileName))					// @violation
	 		Files.copy(file.inputStream, rootLocation.resolve(file.originalFilename))		// @violation
	 	}

	 	return "multipartfile/upload.html"
	 }

	@PostMapping("/upload2")
	fun violation2(@RequestParam("file") file: MultipartFile, request: HttpServletRequest) {
		val fileName = file.originalFilename

		try {
			// val fileUpload = FileUpload()
			val items: ArrayList<FileItem> = fileUpload.parseRequest(request)
			for (i in 0 until items.size) {
				val item = items.get(i)
				if (!item.isFormField && item.size > 0)  {
					val file = File("C:\\$fileName")
					item.write(file)														// @violation
				}
			}
		} catch (e: IOException) {
			logger.error("IOException")
		}
	}

	@PostMapping("/upload3")
	fun violation3(@RequestParam("file") file: MultipartFile) {
		val fileName = file.originalFilename

		val f = File("C:\\$fileName")
		file.transferTo(f)																	// @violation
	}

	@PostMapping("/upload4")
	fun good(@RequestParam("file") file: MultipartFile): String {
		val rootLocation = Paths.get("storage")
		val fileName = file.originalFilename

		if(fileName != null) {
			if(fileName.endsWith(".txt")) {
				Files.copy(file.inputStream, rootLocation.resolve(fileName))				// good
			}
		}
		return "multipartfile/uploadform.html"
	}
}