# minimal base image that only includes the runtime environment
# inherit specific version of base image
FROM eclipse-temurin:21-jre-alpine-3.21

# create directory for application
RUN mkdir app
# create group app and user app
RUN addgroup --gid 1000 -S app && adduser --uid 1000 -S app -G app
# set permissions for app user for the WORKDIR
RUN chown -R app:app app/
 # switch to the created user
USER app
# switch to the app dir
WORKDIR /app

# copy application
ARG JAR_FILE=target/*.jar
COPY ${JAR_FILE} app.jar
ENTRYPOINT ["java","-jar","app.jar"]

# healthchecks
# HEALTHCHECK --interval=5s --timeout=3s CMD curl --fail http://localhost:8080/actuator/health || exit 1
HEALTHCHECK  --interval=5m --timeout=3s CMD wget --no-verbose --tries=1 --spider http://localhost:8080/actuator/health || exit 1