public record SampleRecord(  // @violation
@JsonProperty("name") String name,
@JsonProperty("age") Integer age,
@JsonProperty("address") Address address
) {

    static String STATIC_VARIABLE = "static variable";

    @JsonIgnore
    public String getInfo() {
        return this.name + " " + this.age;
    }

    public static String get() {
        return STATIC_VARIABLE;
    }
}