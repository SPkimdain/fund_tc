@ServiceDescription(
        info = @Desc(
                title = "오아시스테이블",
                desc = "오아시스테이블과 레디언스데이터 join",
                developer = "김철수",
                version = "0.1",
                tags="입금,재지급"
        ),
        history = {
                @Desc(modifyDate="2023.04.20" ,developer="", tags="추가",      desc="신규생성")
        }
)
@Service("AddPayColumnTransfer")
@RequiredArgsConstructor
public class good extends BaseGateHubService {
}

@ServiceDescription(    // @violation
        info = @Desc(
                title = "오아시스테이블",
                desc = "오아시스테이블과 레디언스데이터 join",
                developer = "김철수",
                version = "0.1",
                subDevelopers = "이영희,김준",
                tags= null
        ),
        history = {
                @Desc(modifyDate="2023.04.20" ,developer="", tags="추가",      desc="신규생성")
        }
)
@Service("AddPayColumnTransfer")
@RequiredArgsConstructor
public class bad1 extends BaseGateHubService {
}

@ServiceDescription(    // @violation
        info = @Desc(
                title = "오아시스테이블",
                desc = "오아시스테이블과 레디언스데이터 join",
                developer = "김철수",
                version = "0.1",
                subDevelopers = "이영희,김준",
                tags= ""
        ),
        history = {
                @Desc(modifyDate="2023.04.20" ,developer="", tags="추가",      desc="신규생성")
        }
)
@Service("AddPayColumnTransfer")
@RequiredArgsConstructor
public class bad2 extends BaseGateHubService {
}

@ServiceDescription(    // @violation
        info = @Desc(
                title = "오아시스테이블",
                desc = "오아시스테이블과 레디언스데이터 join",
                developer = "김철수",
                version = "0.1",
                subDevelopers = "이영희,김준"
        ),
        history = {
                @Desc(modifyDate="2023.04.20" ,developer="", tags="추가",      desc="신규생성")
        }
)
@Service("AddPayColumnTransfer")
@RequiredArgsConstructor
public class bad3 extends BaseGateHubService {
}

@ServiceDescription(    // @violation
        info = ""
)
@Service("AddPayColumnTransfer")
@RequiredArgsConstructor
public class bad4 extends BaseGateHubService {
}


@ServiceDescription(    // @violation
        info = null
)
@Service("AddPayColumnTransfer")
@RequiredArgsConstructor
public class bad5 extends BaseGateHubService {
}


@ServiceDescription(    // @violation

)
@Service("AddPayColumnTransfer")
@RequiredArgsConstructor
public class bad6 extends BaseGateHubService {
}