package custom.ncsoft;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/api")
public class PublicSetterInModelAttribute {
    public static class User {
        private String username;
        private boolean admin;

        public String getUsername() {
            return this.username;
        }

        public void setUsername(String username) {
            this.username = username;
        }

        public boolean isAdmin() {
            return this.admin;
        }

        public void setAdmin(boolean admin) {
            this.admin = admin;
        }
    }

    public static class UserUpdateRequest {
        private String username;

        public String getUsername() {
            return this.username;
        }

        public void setUsername(String username) {
            this.username = username;
        }
    }

    @Autowired
    private UserService userService;

    @PostMapping("/updateDanger1")
    public String updateDanger1(@ModelAttribute User user) { // not detected in unit test: checker depends on source-info
        userService.update(user);
        return "redirect:/profile";
    }

    @PostMapping("/updateDanger2")
    public String updateDanger2(@ModelAttribute User user) {  // not detected in unit test: checker depends on source-info
        userService.update(user);
        return "redirect:/profile";
    }

    @PostMapping("/updateSafe")
    public String updateSafe(@ModelAttribute UserUpdateRequest request) {
        User user = userService.findCurrentUser();
        user.setUsername(request.getUsername());
        userService.update(user);
        return "redirect:/profile";
    }
}