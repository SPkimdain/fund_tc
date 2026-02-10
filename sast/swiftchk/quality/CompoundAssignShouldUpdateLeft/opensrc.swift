
public func == (left: Story, right: Story) -> Bool {

            let a = 1;
            //comment
            //comment ////comment
            // commentcomment
            // comment comment

		    return left.id == right.id &&
		    left.title == right.title &&
		    left.url == right.url &&
		    left.commentHTML == right.commentHTML &&
		    left.userDisplayName == right.userDisplayName &&
		    left.userJob == right.userJob &&
		    left.voteCount == right.voteCount &&
		    left.commentCount == right.commentCount &&
		    left.createdAt == right.createdAt &&
		    left.badge == right.badge &&
		    left.userPortraitUrl == right.userPortraitUrl
		}