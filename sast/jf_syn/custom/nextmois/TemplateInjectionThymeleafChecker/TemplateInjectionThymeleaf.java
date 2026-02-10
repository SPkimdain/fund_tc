import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;

public class TemplateInjectionThymeleaf {
    @GetMapping("/display1")
    public String display1(@RequestParam("message") String userMessage, Model model) {
        model.addAttribute("message", "${" + userMessage + "}"); // @violation
        return "myTemplate";
    }

    @GetMapping("/display2")
    public String display2(@RequestParam("message") String userMessage, Model model) {
        String attr = "${" + userMessage + "}";
        String text = "dangerous " + attr;
        model.addAttribute("message", text); // @violation
        return "myTemplate";
    }
}